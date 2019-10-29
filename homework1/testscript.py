import os
from subprocess import check_output

program = "program"
testData = os.listdir("testData")
testDataIn = []
testDataOut = []

for file in testData:
    if "_in.txt" in file:
        testDataIn.append(file)
    elif "_out.txt" in file:
        testDataOut.append(file)

for i in range(len(testDataIn)):
    programOutput = check_output("./program < testData/{}".format(testDataIn[i]), shell=True)
    with open("testData/{}".format(testDataOut[i]), "rb") as outFile:
        outFileText = outFile.read()
        if outFileText == programOutput:
            print("Test {} OK -  expected: {}  |  output: {}".format(i, outFileText, programOutput))
        else:
            print("Test {} NOT OK -  expected: {}  |  output: {}".format(i, outFileText, programOutput))

# os.system("./program")
