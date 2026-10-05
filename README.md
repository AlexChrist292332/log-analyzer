# log-analyzer
A small command-line tool written in C++ that reads a log file and reports statistics about it. Built as a learning project

## Features
- Counts the total number of lines and the total number of errors in a log file

## Build
Requires g++ with C++17 support (Linux)

## Usage
```bash
./log_analyzer sample.log
```

## Example output

```
Total lines: 5
Total errors: 2
```

## Roadmap

- [x] Count lines
- [ ] Count ERROR lines
- [ ] Errors per hour
- [ ] Summary by log level (INFO / WARN / ERROR)
