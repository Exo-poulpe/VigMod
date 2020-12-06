# VigMod

is Vigenere modified with password modulo addition and substract

### How it is work 

Text : 
```
+---------------+
| t | e | s | t |
+---------------+
```
Password : 
```
+---------------------------+
| t | a | r | t | i | n | e |
+---------------------------+
```

Make rotate like vigenere in alphabet 
```
abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!? 
^    ^    ^         ^                    ^                      ^
0    5    10        20                   40                     63
```

Get index by letter : 
```
't' = 19, 't' = 19
=> 19 + 19 = 38 = 'N'
tartine = 19 + 0 + 17 + 19 + 8 + 13 + 4 = 80
=> 80%63 = 17
'N' = 38 + 17 = 55 => '4'
```
Next step substract modulo : 
```
'e' = 4, 'a' = 0
=> 4 + 0 = 4 = 'e'
80%63 = 17
'e' = 4 - 17 = -13
-13 < 0 => -13 + 63 = 50
50 => 'Z'
```