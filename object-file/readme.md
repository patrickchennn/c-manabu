Compile to an object file
```bash
$ gcc -c main.c
$ file main.o 
main.o: ELF 64-bit LSB relocatable, x86-64, version 1 (SYSV), not stripped
```


Compile into final executables:
```bash
$ gcc main.c -o main.fin
$ file main.fin 
main.fin: ELF 64-bit LSB pie executable, x86-64, version 1 (SYSV), dynamically linked, interpreter /lib64/ld-linux-x86-64.so.2, BuildID[sha1]=48a676eabd41971d265cb14601f425a6a389f4ea, for GNU/Linux 3.2.0, not stripped
```