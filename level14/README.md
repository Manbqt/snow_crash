# Level14

At this level we don't have anything in the home repository. After research without success we have tried to disas `getflag` program.  
Using `ghidra` we have the [code](./resources/main.c).  
This code check a ptrace return and verify uid of the user to give or not a flag.  
So to get the last flag we must have a uid like `3014`. Because of this uid is this of flag14 (`/etc/passwd`).   


```bash
(gdb) b main
(gdb) b ptrace
(gdb) b getuid
(gdb) r
(gdb) n
(gdb) n
(gdb) set $eax=0
(gdb) n
(gdb) n
(gdb) set $eax=3014
(gdb) n
Single stepping until exit from function main,
which has no line number information.
Check flag.Here is your token : 7QiHafiNa3HVozsaXkawuYrTstxbpABHD8CPnHJ
0xb7e454d3 in __libc_start_main () from /lib/i386-linux-gnu/libc.so.6
```

It's working ! We have our token. 

```bash
flag14:x:3014:3014::/home/flag/flag14:/bin/bash
level14@SnowCrash:~$ su flag14
Password: 
Congratulation. Type getflag to get the key and send it to me the owner of this livecd :)
flag14@SnowCrash:~$ getflag
Check flag.Here is your token : 7QiHafiNa3HVozsaXkawuYrTstxbpABHD8CPnHJ
```
It's OK we have finished !
