# Level01

We are in a `level01` home but it is (again) empty. During our previously exploration we have read `/etc/passwd` file.  
The password of `flag01` was present but hashed:  

```bash
level01@SnowCrash:~$ cat /etc/passwd
...
flag01:42hDRfypTqqnw:3001:3001::/home/flag/flag01:/bin/bash
...
```

We have used the tool [john the ripper](https://www.varonis.com/fr/blog/john-the-ripper) to crack the password:  

```bash
echo "42hDRfypTqqnw" > snow_scrash_hash.txt
john snow_scrash_hash.txt 
Using default input encoding: UTF-8
...
Proceeding with wordlist:/usr/share/john/password.lst, rules:Wordlist
abcdefg          (?)
...
```

We have try the password: 

```bash
level01@SnowCrash:~$ su flag01
Password: 
Don't forget to launch getflag !
flag01@SnowCrash:~$ getflag
Check flag.Here is your token : f2av5il02puano7naaf6adaaf
flag01@SnowCrash:~$ su level02
Password: 
level02@SnowCrash:~$
```

It's working ! We are now level02
