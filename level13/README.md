# Level13

We have a binary file. When the program is launched, a message is displayed: 

```bash
level13@SnowCrash:~$ ./level13 
UID 2013 started us but we we expect 4242
```

So we can use gdb to try to understand and exploit-it.  
We can see the [program](./resources/main.c) in C.  

We have used gdb to set the value as we want:  

```bash
(gdb) b getuid
(gdb) n
(gdb) set $eax=4242
(gdb) i r $eax
eax            0x1092	4242
(gdb) n
Breakpoint 3, 0x08048478 in ft_des ()
(gdb) c
your token is 2A31L79asukciNyi8uppkEuSx
```

In resume:  
We have put a breakpoint on `getuid` function and we have changed the return value `eax`.  
The condition is satisfied, our guid is `4242`. We have our token.  
