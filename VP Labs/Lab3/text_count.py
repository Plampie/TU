text = str(input(f"Entern text: "))
txt_count = {}
for txt in text:
    if txt in txt_count:
        txt_count[txt] += 1
    else:
        txt_count[txt] = 1
for txt, count in txt_count.items():
    print(f'{txt}:{count}')