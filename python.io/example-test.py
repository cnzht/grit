#-*-coding:utf-8-*-
#daydayupQ3.py
dayfactor = 1.0
for i range (365):
    if  i%3  in [1,2]:
        dayfactor = dayfactor * (1-0.02)
    else:
        dayfactor = dayfactor * (1+0.01)
print("dayfactor={:.3f}".format(dayfactor))
