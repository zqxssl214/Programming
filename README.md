# Programming
## Лабораторная работа 9: Git

### На оценку 3

**1. Узнаем на какой ветке мы находимся**
![alt text](<git status.png>)

Наш **git log** выглядит так:
![alt text](<git log.png>)

**2. Создадим файл sort.c и вставим туда код функции bubble. Теперь наш **git status** выглядит так:**
![alt text](<git status 2.png>)

**3. Закоммитим файл в репозиторий. Теперь git status:**
![alt text](<git status 3.png>)

**4. После добавления комментария в файл наш git status принял вид:**
![alt text](<git status 4.png>)

**5. Мы добавили наши изменение файла с помощью "add"**
![alt text](<git status 5.png>)

**6. После повторного изменения файла и коммита:**
![alt text](<git log 2 status 7.png>)

### Теперь работа с ветками
**1. Создадим новую ветку и убедимся в этом**
![alt text](<git branch.png>)
**Сейчас git status на двух ветках такой**
![alt text](<git st on main.png>)
![alt text](<git st on my branch.png>)

**2. Создадим файл с именем file1.txt и своим именем. Добавим файл и закоммитим его. Используем git log, чтобы увидеть,что наша ветка указывает на новый коммит.**
![alt text](<git log after file1txt.png>)

**3. Вернемся в ветку main и проверим git log здесь**
![alt text](<git log after file 1 txt on main.png>)

**4. Создадим новый файл с именем file2.txt и закоммитим его. Используем git log --oneline --graph --all, чтобы увидеть, что теперь у двух веток разные коммиты.**
![alt text](<git graph all line.png>)

**5. Переключившись на ветку mybranch мы не увидим нашего file2.txt**
![alt text](<ls in mybranch.png>)

С помощью git diff посмотрим разницу между ветками

![alt text](<git diff.png>)


