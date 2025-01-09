cycles=['honda','yamah','suzuki']
message1=f"my first bicyle is {cycles[1].title()}"
cycles[1]="no yamaha"
message2=f"my true first bicycle is {cycles[1].title()}"
print(cycles)
cycles.append('auto')
print(cycles)
del cycles[2]
print(cycles)
thelastone=cycles.pop()
print(cycles)
cycles.remove('honda')
print(cycles)
print(thelastone)
print(message1)
print(message2)

cars=['bmw','audi','toyota','subaru']
print(sorted(cars))
print(cars)
cars.sort()
print(cars)

car=['bmw','audi','toyota','subaru']
car.sort(reverse=True)
print(car)