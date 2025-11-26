# ****Programming****
## **Лабораторная работа 9: Git**

## **На оценку 3**

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


## **На оценку 4**


**Выполнив первые пункты. git diff показывает нам следующее**

![alt text](screenshots/gitdiff1.png)

Но git diff --staged пустой.

![alt text](screenshots/gitdiffstaged.png)

После того как мы проиндексировали sort.c git diff:

![alt text](screenshots/gitdifff2.png)

А вот git diff --staged уже не пустой

![alt text](screenshots/gidiffstaged2.png)

Это говорит нам о том, что git diff показывает изменения в рабочей директории (те, которые мы не проиндексировали)
git diff --staged показывает изменения уже проиндексированные

Наш git status

![alt text](screenshots/gitstatus1.png)

Запустив git restore --staged sort.c наш git status стал таким

![alt text](screenshots/gitstatus2.png)


После индексации файла наш журнал выглядит так:

![alt text](screenshots/zhurnal1.png)

Мы добавили новую строчку в sort.c. Его содержимое:

![alt text](screenshots/catsort.png)

После git restore содержимое sort.c такое:

![alt text](screenshots/catsort2.png)


### **Работа с ветками**

Проделав пункты 1-4 наш git status выглядит так:

![alt text](screenshots/gitstupper.png)

Отредактировав файл greeting.txt git branch и git log такие:

![alt text](screenshots/gitlogst5upper.png)

Переключивишись на main сравним ветки

![alt text](screenshots/gitdiffcatlog.png)

Засмержим ветки

Содержимое greetings.txt

![alt text](screenshots/catgreet.png)

Засмержим mybranch в main 

![alt text](screenshots/gitlogaftmerge.png)

##  **На оценку 5**

Выполнив пункты 1-5 мы получаем такой git log

![alt text](screenshots/5gitlog1.png)

Засмержив ветку branch1 в main получаем конфликт. git status такой

![alt text](screenshots/5gitstatus1.png)

Исправив данный конфликт (объединили) и закоммиттив это git log :

![alt text](screenshots/5gitlogconf2.png)

**Починим Merge конфликты для сортировки MergeSort на python.**

Выполнив пункты 1-7 мы получим такой git log :

![alt text](screenshots/GITLOG.png)

Получаем такой git branch из 4 веток

![alt text](screenshots/branch.png)

Смержим Mergesort-Impl в main и исправляем все конфликты (объединяя)

😎 Пушим изменения 😎

✔ Готово ✔


