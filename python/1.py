cycles=['honda','yamah','suzuki']
message1=f"my first bicyle is {cycles[1].title()}"
cycles[1]="no yamaha"
message2=f"my true first bicycle is {cycles[1].title()}"
print(cycles)
cycles.append('auto')
print(cycles)
print(message1)
print(message2)