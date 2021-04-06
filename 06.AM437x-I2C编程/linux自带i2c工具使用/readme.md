## I2c扫描

通过i2cdetect -l指令可以查看AM437x上的I2C总线，从返回的结果可以看到3个I2C总线。

```shell
[root@nudt ]# i2cdetect -l
i2c-0   i2c             OMAP I2C adapter                        I2C adapter
i2c-1   i2c             OMAP I2C adapter                        I2C adapter
i2c-2   i2c             OMAP I2C adapter                        I2C adapter
```

## I2C设备查询

  若总线上挂载I2C从设备，可通过i2cdetect扫描某个I2C总线上的所有设备。可通过控制台输入i2cdetect -y 2，结果如下所示。

```shell
[root@nudt ]# i2cdetect -y 2
0  1  2  3  4  5  6  7  8  9  a  b  c  d  e  f
00:          -- -- -- -- -- -- -- -- -- -- -- -- --
10: -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --
20: -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --
30: -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --
40: -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --
50: 50 -- -- -- -- -- -- 57 -- -- -- -- -- -- -- --
60: -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --
70: -- -- -- -- -- -- -- --
```

- 说明1：-y为一个可选参数，如果有-y参数的存在则会有一个用户交互过程，意思是希望用户停止使用该I2C总线。如果写入该参数，则没有这个交互过程，一般该参数在脚本中使用。
- 说明2：此处I2C总线共挂载两个设备——PCF8574和AT24C04，从机地址0x50为board configure，从机地址0x57为AT24C04。

## 寄存器内容导出

  通过i2cdump指令可导出I2C设备中的所有寄存器内容，例如输入i2cdump -y 2 0x50，可获得以下内容:

```shell
[root@nudt ]# i2cdump -y 2 0x50
No size specified (using byte-data access)
0  1  2  3  4  5  6  7  8  9  a  b  c  d  e  f    0123456789abcdef
00: 01 00 0d 00 84 08 e8 03 04 4a 00 00 00 00 00 00    ?.?.?????J......
10: 00 00 35 02 36 39 39 2d 38 32 31 38 30 2d 31 30    ..5?699-82180-10
20: 30 30 2d 34 31 30 20 4a 2e 30 ff ff ff ff ff ff    00-410 J.0......
30: ff ff 35 2d 66 4b 04 00 36 2d 66 4b 04 00 00 00    ..5-fK?.6-fK?...
40: 00 00 00 00 37 2d 66 4b 04 00 30 33 32 33 32 31    ....7-fK?.032321
50: 36 31 33 30 35 36 35 ff ff ff ff ff ff ff ff ff    6130565.........
60: ff ff ff ff ff ff ff ff ff ff ff ff ff ff ff ff    ................
70: ff ff ff ff ff ff ff ff ff ff ff ff ff ff ff ff    ................
80: ff ff ff ff ff ff ff ff ff ff ff ff ff ff ff ff    ................
90: ff ff ff ff ff ff 4e 56 43 42 1c 00 4d 31 00 00    ......NVCB?.M1..
a0: 35 2d 66 4b 04 00 36 2d 66 4b 04 00 37 2d 66 4b    5-fK?.6-fK?.7-fK
b0: 04 00 ff ff ff ff ff ff ff ff ff ff ff ff ff ff    ?...............
c0: ff ff ff ff ff ff ff ff ff ff ff ff ff ff ff ff    ................
d0: ff ff ff ff ff ff ff ff ff ff ff ff ff ff ff ff    ................
e0: ff ff ff ff ff ff ff ff ff ff ff ff ff ff ff ff    ................
f0: ff ff ff ff ff ff ff ff ff ff ff ff ff ff ff 96    ...............?
```

  i2cdump -y 2 0x50指令中：

- -y    代表取消用户交互过程，直接执行指令；
- 2     代表I2C总线编号；
- 0x50  代表I2C设备从机地址，此处选择配置芯片的高256字节内容。

## 寄存器内容写入

  如果向I2C设备中写入某字节，可输入指令

```shell
[root@nudt ]# i2cset -y 2 0x50 0x00 0x13
```

- -y    代表曲线用户交互过程，直接执行指令
- 2     代表I2C总线编号
- 0x50  代表I2C设备地址，此处选择AT24C04的低256字节内容
- 0x00  代表存储器地址
- 0x13  代表存储器地址中的具体内容

## 寄存器内容读出

```shell
[root@nudt ]# i2cget -y 2 0x50 0x00
0x13
```

  如果从I2C从设备中读出某字节，可输入执行i2cget -y 2 0x50 0x00，可得到以下反馈结果

- -y    代表曲线用户交互过程，直接执行指令
- 2     代表I2C总线编号
- 0x50  代表I2C设备地址，此处选择AT24C04的低256字节内容
- 0x00  代表存储器地址