# DuckDB - Encodings

This extension allows you to register all encodings available in the [ICU data repository](https://github.com/unicode-org/icu-data/tree/main/charset/data/ucm). It supports a total of 990 different encodings. The names of the encodings match the `<code_set_name>` option in each file.
Stateful encodings (the SO/SI-switched EBCDIC tables such as `ibm-930`/`ibm-939`, and ISO-2022 variants) cannot be decoded with a stateless table lookup and are therefore not registered.
It currently only performs encoding when reading data, converting from `<code_set_name>` to `UTF-8`.

## Usage
To use this extension, you must first install and load it in DuckDB.

```sql
INSTALL encodings;
LOAD encodings;
```

After that, all encodings are initialized in your database instance. To use them, simply refer to the correct encoding.

```sql
FROM read_csv('my_shift_jis.csv', encoding = 'shift_jis')
```

Besides the ICU `<code_set_name>`, every encoding that has a Python codec also accepts the names Python (and therefore tools such as `chardet`) use for it, e.g. `windows-1252`, `ISO-8859-4`, `iso8859-4`, `latin1`, `KOI8-R`, `EUC-KR` or `cp932`. Names are matched case-insensitively. Note that `latin1`/`iso-8859-1` map to the full ISO 8859-1 table (bytes `0x80`-`0x9F` decode to C1 control characters, as in Python), while DuckDB's built-in `latin-1` rejects those bytes.

The full list of accepted names can be queried with `duckdb_encodings()`:

```sql
SELECT name FROM duckdb_encodings() WHERE name LIKE '%1252%';
```

## Building
### Generating Encoding Maps
The conversion tables of all encodings are generated from the Unicode data, which is inlined in the `third_party` folder. They are stored in a single dataset, `src/encodings_dataset.cpp`, which holds all tables (similar tables are stored once, and all of them are compressed together with ZSTD) and the names they are registered under; `src/encodings_dataset.manifest` lists its contents in a readable form. The extension unpacks a table the first time one of its encodings is used. Any changes to these files should be made by modifying the `scripts/converter.py` script, rather than editing the files manually.
If it's necessary to regenerate the dataset (e.g., due to a bug fix in the replacement maps), simply run the following, which needs the `zstandard` Python package or the `zstd` command line tool:
```bash
python scripts/converter.py
```

It is also important to notice that the `scripts/converter.py` script also generates the `test/sql/encodings.test` test file and the CSV files it reads in `data`.

### Build steps
Now to build the extension, run:
```sh
make
```
The main binaries that will be built are:
```sh
./build/release/duckdb
./build/release/test/unittest
./build/release/extension/encodings/encodings.duckdb_extension
```
- `duckdb` is the binary for the duckdb shell with the extension code automatically loaded.
- `unittest` is the test runner of duckdb. Again, the extension is already linked into the binary.
- `encodings.duckdb_extension` is the loadable binary as it would be distributed.

## Running the tests
Different tests can be created for DuckDB extensions. The primary way of testing DuckDB extensions should be the SQL tests in `./test/sql`. These SQL tests can be run using:
```sh
make test
```

### Installing the deployed binaries
To install your extension binaries from S3, you will need to do two things. Firstly, DuckDB should be launched with the
`allow_unsigned_extensions` option set to true. How to set this will depend on the client you're using. Some examples:

CLI:
```shell
duckdb -unsigned
```

Python:
```python
con = duckdb.connect(':memory:', config={'allow_unsigned_extensions' : 'true'})
```

NodeJS:
```js
db = new duckdb.Database(':memory:', {"allow_unsigned_extensions": "true"});
```

Secondly, you will need to set the repository endpoint in DuckDB to the HTTP url of your bucket + version of the extension
you want to install. To do this run the following SQL query in DuckDB:
```sql
SET custom_extension_repository='bucket.s3.eu-west-1.amazonaws.com/<your_extension_name>/latest';
```
Note that the `/latest` path will allow you to install the latest extension version available for your current version of
DuckDB. To specify a specific version, you can pass the version instead.

After running these steps, you can install and load your extension using the regular INSTALL/LOAD commands in DuckDB:
```sql
INSTALL encodings
LOAD encodings
```
