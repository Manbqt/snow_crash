# Level00

When we fill the credentials given in the subject, we arrived in `/home/level00`. This repository is empty. We must search hint. So we have used the [find](https://www.plesk.com/blog/various/find-files-in-linux-via-command-line/) command:  

```bash
level00@SnowCrash:~$ find / -user flag00 2>/dev/null
/usr/sbin/john
/rofs/usr/sbin/john
level00@SnowCrash:~$ cat /usr/sbin/john
cdiiddwpgswtgt
```

We have a string who seems be encrypted. So we have use an [online tool](https://www.dcode.fr/identification-chiffrement) to try identify the type of encryption. We obtain a lot of strings but one stands out `nottoohardhere`.  It's a `rot11`. 

```bash
level00@SnowCrash:~$ su flag00
Password: 
Don't forget to launch getflag !
flag00@SnowCrash:~$ getflag
Check flag.Here is your token : x24ti5gi3x0ol2eh4esiuxias
flag00@SnowCrash:~$ su level01
Password: 
level01@SnowCrash:~$
```

