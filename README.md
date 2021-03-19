## Bytecode Writer
## By CompiledCode

## Example Code:
```c++
luau::bytecode_writer writer;

writer << 0x1 << 0x2 << 0x3;
writer.write_compressed(5);
writer.write_string("hello", 5);

const auto& bytecode = writer.bytecode;
```
