# Display with 4 * max7219
## 一、关于MAX7219
* MAX7219采用的是SPI接口，而非I2C接口
* Dout脚滞后Din脚16个CLK周期

## 二、准备
### 1、4个MAX7219级联模块
![image](https://github.com/github150620/max7219x4/blob/master/snapshot/max7219.jpg)
![image](https://github.com/github150620/max7219x4/blob/master/snapshot/max7219_back.jpg)

### 2、ATTiny85开发板
![image](https://github.com/github150620/max7219x4/blob/master/snapshot/attiny85.jpg)
![image](https://github.com/github150620/max7219x4/blob/master/snapshot/attiny85_back.jpg)

### 3、5V电源模块
4个MAX7219模块共256个LED，功率相对一般模块要大很多，建议使用L7805等电流稍大一点的电源模块。（AMS1117电流较小）

### 4、Arduino
不需要添加第三方库。

## 三、连接
| ATTINY85 | MAX7219 |
| :-: | :-: |
| PB0 | DIN |
| PB1 | CS |
| PB2 | CLK |
| GND | GND|

## 四、程序代码
见max7219x4目录。

## 五、运行
![image](https://github.com/github150620/max7219x4/blob/master/snapshot/running.jpg)

## 六、疑问
有问题请联系QQ597540267。