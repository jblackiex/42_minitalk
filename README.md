# 42_minitalk
A small data exchange program using UNIX signals

Produce `server` & `client` executables
- `client` must communicate a string passed as a parameter to `server` *(referenced by its process ID)* which then displays it
- Use `SIGUSR1` & `SIGUSR2` signals **ONLY**

Compile with:
```shell
make
```

👇🏼 UNICODE characters SUPPORT
```shell
make bonus
```

## 📚 VERSIONS

--- > [**bits version**](https://github.com/jblackiex/42_minitalk/tree/main/bits_version)

--- > no unicode support -> [**ASCII version**](https://github.com/jblackiex/42_minitalk/tree/main/ascii_version)
