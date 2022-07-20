# minishell
+ nonoaa: 파싱, 구조담당
+ hyeok230: 기능실행 담당

## 실행화면
<img width="921" alt="Screen Shot 2022-07-20 at 5 07 00 PM" src="https://user-images.githubusercontent.com/56538203/179931151-de8068cb-c3a5-4f23-bab5-003a1cfe14eb.png">

## 과제설명
You must program a mini UNIX command interpreter.

이 인터프리터는 명령 프롬프트(예를 들면 $> )를 띄워야하고, 사용자가 enter 키를 눌러 명령줄(command line)을 입력할 때 까지 기다려야 한다.

프롬프트는 명령이 완전히 실행된 후에만 다시 표시된다.
PATH 변수 및 상대/절대 경로에 기반한 실행 파일(The executable)을 올바르게 찾아 실행한다.

실행 파일을 찾을 수없는 경우 오류 메시지를 표시하고 프롬프트를 다시 표시해야 한다.
다음과 같은 쉘 내장 함수를 구현한다.

echo (with option -n)
cd (with only relative or absolute path)
pwd
export
unset
env (without any options and any arguments)
exit

다음 기능을 일반 bash와 동일하게 동작해야하도록 구현한다.

multiline commands를 제외한 ' , "
file descriptor aggregation를 제외한 리다이렉션(<, >, >>)
파이프(|)
환경변수($ followed by characters)
$?
ctrl-C, ctrl-D, ctrl-\

## 플로우차트
![image](https://user-images.githubusercontent.com/56538203/179931870-7008e656-ba92-4fc7-8eb6-933aff7a675e.png)
