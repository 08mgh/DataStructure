#循环原油产量换算程序
price = float(input("请输入原油价格"))
while True:
    s = input("请输入原油数量")
    if s.lower() == 'n':
        break
    if s.endswith("bbl"):
        num = float(s[:-3])
        total = num * price
        print("{0:.2f}".format(total))
    elif s.endswith("t"):
        num = float(s[:-1])
        barrel = num / 0.14
        total = barrel * price
        print("{0:.2f}".format(total))
    else:
        print("输入格式错误")