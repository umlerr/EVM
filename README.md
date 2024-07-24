# Организация ЭВМ и систем

# Лабораторная работа №1. 
## ИССЛЕДОВАНИЕ ВНУТРЕННЕГО ПРЕДСТАВЛЕНИЯ РАЗЛИЧНЫХ ФОРМАТОВ ДАННЫХ

Цель работы: знакомство с внутренним представлением различных типов данных, используемых компьютером при их обработке.

Порядок выполнения работы

1. В зависимости от номера варианта задания разработать алгоритм ввода с клавиатуры требуемых типов данных и показать на экране их внутреннее представление в двоичной системе счисления. 
2. Написать и отладить программу на языке С++, реализующую разрабо-танный алгоритм. Программа должна
- иметь дружественный интерфейс
- выводить на экран информативное сообщение при вводе некорректных данных
- предложить повторный ввод пока не будут введены корректные данные
3. В соответствии с заданием дополнить разработанный ранее алгоритм блоками для  выполнения преобразования двоичного полученного кода исход-ного типа данных и последующего  вывода  преобразованного кода в двоич-ной системе счисления и  в формате исходного данного.

Вар - 13 (unsigned int, float): Выполнить зеркальную перестановку в группе рядом стоящих разря-дов, количество которых и номер младшего разряда в группе задаются с кла-виатуры.

# Лабораторная работа №2.
## ИССЛЕДОВАНИЕ ВИДЕОСИСТЕМЫ (ТЕКСТОВЫЙ РЕЖИМ)

Цель работы: изучение работы с видеосистемой в текстовом режиме, освое-ние приемов использования цветовой палитры: измене¬ние цвета символов и фона на всем экране и в отдельном окне.

1. Написать программу, чтобы в окно с координатами (x1,у1,х2,у2) с шагами Т (секунд) и S (строк) выводилась строка при всех возможных комбина-циях цвета фона и цвета символов.
2. Строка содержит обозначение цвета фона и символа.
3. Для каждой комбинации цветов в окне должны выводиться номера или символьные обозначения цветов фона и символов.
4. Цвет окна должен соответствовать цвету фона.
5. Дополнить программу из п.1 скроллингом окна с направлением в соот-ветствии с вариантом, используя функции прерывания 10h BIOS. Пример скроллинга приведен в мет.указаниях.

Вар - 13: Координаты окна (x1 = 10, y1 = 12, x2 = 70, y2 = 23), Обозначение цвета фона - Англ, Обозначение цвета символа - Англ, Шаг T - 0.3, Шаг S - 1, Направление - Вверх. 

# Лабораторная работа № 3. 
## ИССЛЕДОВАНИЕ ВИДЕОСИСТЕМЫ (ГРАФИЧЕСКИЙ РЕЖИМ)

Цель работы: изучение работы с видеосистемой в графическом режиме, вывод графика заданной функции с масштабированием и разметкой осей.

Порядок выполнения работы

1. Разработать программу для вывода на экран графика заданной функции.  
2. Произвести разметку осей и проставить истинные значения точек.
3. Найти максимальное значение функции на заданном интервале и вывести в отдельное окно на экране вместе с графиком.

Вар - 13: Sin2(x)- Cos3(x)	Диапазон аргумента (π/2;5π)

# Лабораторная работа № 4.
## КЛАВИАТУРА IBM PC. ИСПОЛЬЗОВАНИЕ ПРЕРЫВАНИЙ

Цель работы: изучение возможностей работы с клавиатурой, ознакомление со стандартными средствами библиотеки C++ и средствами системы прерыва-ний DOS и BIOS, обслуживающими клавиатуру.

Порядок выполнения работы

1. Разработать, написать и отладить программу управления пе¬ремещением  символа (например, "*") в пределах заданного на экране окна.   Для управле-ния использовать клавиши  из  набора:   "стрелка вверх"   (СтВВ),   "стрелка вниз"  (СтВН),   "стрелка вправо" (СтВП), "стрелка влево" (СтВЛ) или функци-ональные клавиши Fl - F12. Для ввода использо-вать стандартные функции языка C++ (getch, getche, kbhit, bioskey). Сохра-нить отлаженную программу.
2. Изменить программу, заменив стандартные функции библиотеки C++(getch, getche, kbhit, bioskey) своими.   Для написания функций используй-те заданное прерывание INT 21h  или INT 16h (см. таблицу). Если его возмож-ностей не достаточно, то замените его по своему усмотрению. Сохраните отла-женную программу.
3. Две отлаженные программы предъявить преподавателю.

Вар - 13: x1 = 10, y1 = 12, x2 = 70, y2 = 	23, движение - постоянное,	клавиши управления: СтВВ,  СтВН, номер прерывания - INT 16h

# Лабораторная работа № 5.
## ИСПОЛЬЗОВАНИЕ АППАРАТНЫХ ПРЕРЫВАНИЙ

Цель работы: знакомство с различного вида аппаратными прерываниями и создание собственных подпрограмм обработки прерываний.

Порядок выполнения работы

Разработать алгоритм, используя аппаратное прерывание, при котором каждый введенный символ с клавиатуры будет дублироваться на экране.



