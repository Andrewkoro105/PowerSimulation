# EN

## description
this game is a logic circuit simulator (like redstone in minecraft) but with an emphasis on binary operators
## installation
to install, download exe file and image folder
## use
### startup
A simple startup will create/open a test.mps file that is 32 by 32 blocks in size.  
The input of the arguments is supported :
- the path to the file to be opened/created (if only the path is specified and there is no such file, the file will be created 32 by 32 blocks)
- world size in width
- world size in height
### control
- `w, a, s, d` - move
- `e` - switch block to the next
- `q` - switch block to the previous block
- `r` - block rotate
- `LMB` - put current block
- `RMB` - deleting block (putting block of air)
- `Average MB` - zoom
## blocks
#### 0. air
> dielectric
#### 1. wire
> when any power is applied from the rear or power above 1 from any block it starts to output energy with a level 2 on the front and a level 1 on the sides
#### 2. generator
> continuously outputs energy with level 2 on all sides
#### 3. The logical `and'
> takes energy on the sides and outputs a second power signal if both inputs are greater than 0
#### 4. The logical `not`
> the complete opposite of the wire, when any power is applied from the rear or with a force higher than 1 from any block, it stops outputting
#### 5. The logical operator `xor`
> takes energy on the sides and outputs a signal on the front equal to 2, if one is 0 and the other is greater than 0
#### 6. The logical operator `xand`
> takes energy on the sides and outputs a signal at the front equal to 2 if they are both either greater than 0 or equal to 0
#### 7. intersection
> it outputs energy from the bottom and similarly from Left to Right
#### 8. lamp
> lights up if power is applied to it

# RU
## описание
данная игра является симулятором логических схем (на подобие красного камня в minecraft) но с упором на двоичные операторы
## установка
для установки нужно скачать exe файл и папку image
## использование
### запуск
при простом запуске создаётся/открывается файл test.mps размером 32 на 32 блока.  
Поддерживается ввод аргументов :
- путь к открываемому/создаваему  файлу (если указан только путь и при этом такого файла не будет , файл создастся 32 на 32 блока)
- размер карты в ширину
- размер карты в высоту
### управление
- `w, a, s, d` - перемещение
- `e` - переключение блока на следующий
- `q` - переключение блока на предыдущий
- `r` - поворот блока
- `ЛКМ` - постановка текущего блока
- `ПКМ` - удаление блока (постановка блока воздуха)
- `Средн.КМ` - зум
## блоки
#### 0. воздух
> диэлектрик
#### 1. провод
> при подаче энергии любой силы с заде или энергии с силой выше 1 с любого блока он начинает выдавать энергию с уровнем 2 спереди и с уровнем 1 по бокам
#### 2. генератор
> постоянно выдаёт энергию с уровнем 2 со всех сторон
#### 3. логическое `and`
> принимает энергию по бокам и выдаёт сигнал второй силы, если оба входа больше 0
#### 4. логический `not`
> полная противоположность проводу, при подаче энергии любой силы с заде или с силой выше 1 с любого блока, она престаёт выдаётся
#### 5. логический оператор `xor`
> принимает энергию по бокам и выдаёт сигнал спереди равный 2, если один равен 0, а другой больше 0
#### 6. логический оператор `xand`
> принимает энергию по бокам и выдаёт сигнал спереди равный 2, если они оба либо больше 0, либо равны 0
#### 7. перекрёсток
> при подаче энергии снизу он выдает её сверху и аналогично слева на право
#### 8. лампа
> загорается если подать на неё энергию