from os import system

code = ""
temp = ""

actual_line = ""

some_words = {"!!":"!=",">>":"==","<--":"=","--->":"{","<---":"}","INX":"++"}
some_chars = {"]":")" , "[":"("}
last_ones  = {"@":"[" , "_":"]"}

with open("excc.c","r") as somefile:
	precode = somefile.read()

for line in precode.splitlines():
	for word in line.split():
		if word in some_words:
			line = line.replace(word,some_words[word])
	for char in line:
		if char in some_chars:
			line = line.replace(char,some_chars[char])
	for char in line:
		if char in last_ones:
			line = line.replace(char,last_ones[char])
	print(line)
	code += line + "\n"

with open("excc2.c","w+") as somefile:
	somefile.write(code)
