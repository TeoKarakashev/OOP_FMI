# Sample input and output for the application
### All commands are run one after another
### The output may be diffrent if the commands are not executed as its shown below!

### On loading the storage should contains
```
milk|2022-05-11|2022-08-18|Vereq|874|M|1|1|874|Milk from happy cows
milk|2022-05-11|2022-08-11|Vereq|100|M|2|1|100|Milk from happy cows
apple|2022-05-09|2022-06-10|Foxconn|675|A|1|1|675|Red apples
banana|2022-05-10|2022-07-15|BananaCo|430|B|1|1|430|High class bananas
Jelly|2022-04-28|2023-07-15|Zaharna fabrika|469|J|1|1|469|chocolate flavour
protein|2021-12-30|2023-10-10|My protein|320|P|1|1|320|Cookies and cream flavour 
```

**Sample input**:

```
add
2022-05-10
milk
2022-08-11
Vereq
500
From happy cows
```

```
print

//milk|1474
//apple|675
//banana|430
//Jelly|469
//protein|320 
```
```
print as admin

//milk|2022-05-11|2022-08-18|Vereq|874|M11874|Milk from happy cows
//milk|2022-05-11|2022-08-11|Vereq|600|M21600|Milk from happy cows
//apple|2022-05-09|2022-06-10|Foxconn|675|A11675|Red apples
//banana|2022-05-10|2022-07-15|BananaCo|430|B11430|High class bananas
//Jelly|2022-04-28|2023-07-15|Zaharna fabrika|469|J11469|chocolate flavour
//protein|2021-12-30|2023-10-10|My protein|320|P11320|Cookies and cream flavour 
```
```
clearence
2022-07-14
// expiring products were removed and saved in file with name: cleanup-2022-07-14.txt 
```

*file should contains*
```
apple|2022-05-09|2022-06-10|Foxconn|675|A11675|Red apples
banana|2022-05-10|2022-07-15|BananaCo|430|B11430|High class bananas 
```
```
remove
protein
70
```
```
print
//milk|1474 
//Jelly|469
//protein|250 
```
```
remove
protein
700
// There are only 250 products left of your type: 
1
```
```
print
//milk|1474
Jelly|469 
```
```
log
0001-01-01
9999-12-31

//milk|add|500|M21600|2022-05-10
//banana|remove|430|B11430|2022-07-15
//apple|remove|675|A11675|2022-06-10
//protein|remove|70|P11320|2023-10-10
//protein|remove|250|P11250|2023-10-10 
```

```
close
```
