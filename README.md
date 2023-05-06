# 42_minitalk
A small data exchange program using UNIX signals

Produce `server` & `client` executables
- `client` must communicate a string passed as a parameter to `server` *(referenced by its process ID)* which then displays it
- Use `SIGUSR1` & `SIGUSR2` signals **ONLY**

Compile with:
```shell
make all
```

👇🏼 UNICODE characters SUPPORT
```shell
make bonus
```

## 📚 VERSIONS

--- > bits version: [**read_BUFFER_SIZE_bytes**](https://github.com/jblackiex/42_get_next_line/tree/main/read_BUFFER_SIZE_bytes).

--- > ASCII version (no unicode support): [**read_1_byte**](https://github.com/jblackiex/42_get_next_line/tree/main/read_1_byte) version.
