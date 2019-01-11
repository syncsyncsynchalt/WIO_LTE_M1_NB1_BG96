
CubeMX起動するたびにdo not gen mainが記録されてない。


マイコンの周波数 120MHz ぐらいを境にWioSK6812のLED制御が壊れる。タイミング決め打ちだから。適当にWioSK6812.cppのDelayLoop変える。


./examples/Grove3AxisDigitalAccelerometer15.cpp
Groveの3軸加速度センサの安い方。
APB1とAPB2の周波数を 8MHz 未満にすると I2C がちゃんと動かない。わからない。特にまだ困ってないのでそのままにしています。



