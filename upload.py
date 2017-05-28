import sys
import subprocess

if __name__ == "__main__":
	toughness_list = ["Not Defined", "easy", "medium", "hard", "expert"]
	toughness_list2 = ["0: Not Defined", "1: Easy", "2: Medium", "3: Hard", "4: Expert"]
	prob_name = ""
	prob_url = ""
	toughness = 0
	percentail = 0.001
	comments = ""
	prog_language = ""
	file_name = ""
	notepad_path = "C:\\Program Files (x86)\\Notepad++\\notepad++.exe"
	word_path = "C:\\Program Files (x86)\\Microsoft Office\\root\\Office16\\WINWORD.EXE"
	number_of_programs_line = 22
	
	
	print "Enter the name of the problem:"
	prob_name = sys.stdin.readline()
	prob_name = prob_name.strip()
	print "Enter the problem URL:"
	prob_url = sys.stdin.readline()
	prob_url = prob_url.strip()
	print "Enter the toughness of the problem: (1:Easy, 2:Medium, 3:Hard, 4:Expert)"
	toughness = int(sys.stdin.readline())
	print "Enter the programming language (file extension): (c, cpp, java, py)"
	prog_language = sys.stdin.readline()
	prog_language = prog_language.strip()
	print "Enter the percentail:"
	percentail = float(sys.stdin.readline())
	print ("Enter description or comments related to the problem:")
	comments = sys.stdin.readline()
	comments = comments.strip()
	
	index_md = open("index.html","r+")
	lines = index_md.readlines()
	
	number = int(lines[number_of_programs_line].split(":")[1])
	number = number + 1
	tempo = lines[number_of_programs_line]
	tempo = tempo.split(":")[:1]
	tempo = "".join(tempo) + ": " + str(number)
	lines[number_of_programs_line] = tempo + "\n"
	
	print "New record's Number :", number, " and line: " + lines[number_of_programs_line]
	record = ""
	record = record + "\t\t\t<td> " + str(number) + " </td>\n"
	record = record + "\t\t\t<td> " + "<a href=\"" + prob_url + "\" target=\"_blank\">" + prob_name +  " </a> </td>\n"
	file_name = "_".join(prob_name.split()) + "." + prog_language
	record = record + "\t\t\t<td> " + "<a href=\"https://github.com/pradeep0605/Leetcode/blob/master/code/" + toughness_list[toughness] 
	record = record + "/" + file_name + "?raw=true\" target=\"_blank\"> " + file_name + " </a> </td>\n"
	record = record + "\t\t\t<td> " + toughness_list2[toughness] + " </td>\n"
	record = record + "\t\t\t<td> " + str(percentail) + " </td>\n"
	record = record + "\t\t\t<td> " + comments + " </td>\n"
	
	word_file_name = "_".join(prob_name.split()) + ".docx"
	
	record = record + "\t\t\t<td> " + "<a href=\"https://github.com/pradeep0605/Leetcode/blob/master/code/" + toughness_list[toughness] 
	record = record + "/" + word_file_name + "?raw=true\" target=\"_blank\"> " + word_file_name + " </a> </td>\n"
	
	record = "\t\t<tr>\n" + record + "\t\t</tr>\n"
	
	subprocess.call ([notepad_path, "code\\" + toughness_list[toughness] + "\\" + file_name])

	subprocess.call(["touch", "code\\" + toughness_list[toughness] + "\\" + word_file_name])

	subprocess.call([word_path, "code\\" + toughness_list[toughness] + "\\" + word_file_name])
	
	tempo =[record]
	result = lines[:len(lines) - 4] + tempo + lines[len(lines) - 4:]
	
	out_file = open("index.html", "w")
	out_file.writelines(result)
	out_file.close()

	print "========== All Files Created ================================="
	print "Sure you want to commit to git ? (Y/N)"
	decision = sys.stdin.readline().strip()
	if decision == "Y" or decision == "y" or decision == "Yes" or decision == "YES":
		print "Uploading tot git"
		subprocess.Popen(["git", "add", "index.html"]).wait()
		subprocess.Popen(["git", "add", "code/"]).wait()
		subprocess.Popen(["git", "add", "upload.py"]).wait()
		subprocess.Popen(["git", "commit", "-m", "\"Checking-in: " + prob_name + " Problem\""]).wait()
		subprocess.Popen(["git", "push"]).wait()