with open("stud-out.txt","r") as stud_out:
	with open("your-out.txt","r") as your_in:
		with open("diffLines.txt", "w") as diff:
			for i, (studLine, yourLine) in enumerate(zip(stud_out, your_in)):
				studLine = studLine.split()
				yourLine = yourLine.split()
				if len(studLine)!=len(yourLine):
					diff.write(f"Different path lengths at line {i+1}, mine is {len(studLine)} long: {studLine}, and yours is {len(yourLine)} long: {yourLine}\n")
