# Programming
## Лабораторная работа 9: Git

### На оценку 3

**1. Узнаем на какой ветке мы находимся**

![alt text](screenshots/git_status.png)

Наш **git log** выглядит так:

![alt text](screenshots/gitlog.png)

**2. Создадим файл sort.c и вставим туда код функции bubble. Теперь наш **git status** выглядит так:**
![alt text](screenshots/git_status2.png)

**3. Закоммитим файл в репозиторий. Теперь git status:**
![alt text](screenshots/git_status3.png)

**4. После добавления комментария в файл наш git status принял вид:**
![alt text](screenshots/git_status4.png)

**5. Мы добавили наши изменение файла с помощью "add"**
![alt text](screenshots/git_status5.png)

**6. После повторного изменения файла и коммита:**
![alt text](screenshots/gitlog2status7.png)

### Теперь работа с ветками
**1. Создадим новую ветку и убедимся в этом**

![alt text](screenshots/git_branch.png)


**Сейчас git status на двух ветках такой**

![alt text](screenshots/gitstonmain.png)

![alt text](screenshots/gitstonmybranch.png)

**2. Создадим файл с именем file1.txt и своим именем. Добавим файл и закоммитим его. Используем git log, чтобы увидеть,что наша ветка указывает на новый коммит.**
![alt text](screenshots/gitlogafterfile1txt.png)

**3. Вернемся в ветку main и проверим git log здесь**
![alt text](screenshots/gitlogafterfile1txtonmain.png)

**4. Создадим новый файл с именем file2.txt и закоммитим его. Используем git log --oneline --graph --all, чтобы увидеть, что теперь у двух веток разные коммиты.**
![alt text](screenshots/gitgraphallline.png)

**5. Переключившись на ветку mybranch мы не увидим нашего file2.txt**
![alt text](screenshots/ls_in_mybranch.png)

С помощью git diff посмотрим разницу между ветками

![alt text](screenshots/gitdiff.png)


