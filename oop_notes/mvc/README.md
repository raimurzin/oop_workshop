**Model, View, Controller (MVC) — это шаблон (паттерн) программирования, разделяющий архитектуру приложения на три модуля: 
  модель (Model) - предоставляет/изменяет данные приложения, реагируя на команды контроллера;  
  представление (View) - визуализирует полученную информацию от модели на уровне пользовательского интерфейса; 
  контроллер (Controller) - обеспеченивает взаимодействие с системой, обрабатывая действия пользователя.**
Простыми словами, он позволяет изменять каждый компонент независимо друг от друга для простой разработки и поддержки веб-приложений. 

Концепцию MVC сформулировал Трюгве Реенскауг в компании Xerox PARC еще в 1978 году. 

![image](https://github.com/user-attachments/assets/81e8aeb6-f022-4170-a8e8-3f9b3dd1d38a)

Модель MVC решает следующие задачи:
  1) изменение только пользовательского интерфейса, а не бизнес-логики приложения;  
  2) использование в одном приложении разных интерфейсов с возможностью выбора;  
  3) замена реакции приложения на действия пользователя за счет использования другого контроллера.

```
Пример MVC-архитектуры - персональный компьютер
контроллер — клавиатура или мышь. С их помощью пользователь вводит команды;
модель — системный блок, в котором происходит обработка команд и хранятся системные и пользовательские файлы;
представление — монитор, на котором визуализируется работа системного блока.
```
