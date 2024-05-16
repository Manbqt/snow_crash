# Level00

When we fill the credentials given in the subject, we arrived in `/home/level00`. This repository is empty. We must search hint. So we have used the [find](https://www.plesk.com/blog/various/find-files-in-linux-via-command-line/) command:  

```bash
level00@SnowCrash:~$ find / -user flag00 2>/dev/null
/usr/sbin/john
/rofs/usr/sbin/john
level00@SnowCrash:~$ cat /usr/sbin/john
cdiiddwpgswtgt
```
We have a string who seems be encrypted. So we have use an [online tool](https://www.cachesleuth.com/multidecoder/) to try decrypt it. We obtain a lot of strings but one stands out `nottoohardhere`.  

```bash
level00@SnowCrash:~$ su flag00
Password: 
Don't forget to launch getflag !
flag00@SnowCrash:~$ getflag
Check flag.Here is your token : x24ti5gi3x0ol2eh4esiuxias
```

