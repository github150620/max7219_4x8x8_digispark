# Display with 4 * max7219
## 一、准备
### 1、4个MAX7219级联模块
![image](https://github.com/github150620/max7219x4/blob/master/snapshot/max7219.jpg)
![image](https://github.com/github150620/max7219x4/blob/master/snapshot/max7219_back.jpg)

### 2、ATTiny85开发板
![image](https://github.com/github150620/max7219x4/blob/master/snapshot/attiny85.jpg)
![image](https://github.com/github150620/max7219x4/blob/master/snapshot/attiny85_back.jpg)

### 3、5V电源模块
### 4、Arduino

## 二、连接
| ATTINY85 | MAX7219 |
| :-: | :-: |
| PB0 | DIN |
| PB1 | CS |
| PB2 | CLK |
| GND | GND|

## 三、代码
见max7219x4目录。

## 四、运行
![image](https://github.com/github150620/max7219x4/blob/master/snapshot/running.jpg)