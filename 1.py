# sampledata.txtファイルを"読み込みモード"で開く
file_data = open("1.txt", "r")

# 読み込んだテキストファイルを１行ずつ表示
for line in file_data:
    if line % 2 == 0:
        print(line)

# 開いたファイルを閉じる
file_data.close()
