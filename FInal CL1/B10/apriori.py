# DO THIS IF YOU WANT TO EVALUATE RUN TIME IN PYTHON : 


#import timeit
#start_time = timeit.default_timer()

# code you want to evaluate

#elapsed = timeit.default_timer() - start_time




import collections

def prune(last_table,min_sup):
    items=last_table.keys()
    #print items
    for item in items:
        if last_table[item]<min_sup:
            last_table.pop(item,None)

def get_sup_count(db,line):
    items=line.split(',')
    count=0
    for i in db:
        if set(items).issubset(set(i)):     #seti is each transaction 
            count=count+1
    return count

def self_join(db,last_table,k):
    items=last_table.keys()
    last_table.clear()     # {}
    for i in xrange(len(items)):
        j=i+1
        keysi=items[i].split(',')               # items[i] : Keychain (or Keychain,Onion)   keysi  : ['Keychain'](or ['Keychain', 'Onion'])
        while j<(len(items)):
            keysj=items[j].split(',')
            print ' '
            nset=list(set(keysi)|set(keysj))
            print nset
            if(len(nset)==k):
                line=""
                for l in xrange(len(nset)-1):
                    line=line+str(nset[l])+','
                line=line+str(nset[l+1])
                last_table[line]=get_sup_count(db,line)
            j=j+1
            
f=open('transactions.csv','r')
db=[]
last_table=dict()           #dictionary containing .keys .values

for line in f:
    line=line.replace('\n','')
    fline=line.split(',')
    db.append(fline)

for trans in db:
    for item in set(trans):
        if last_table.has_key(item) and item!='-':
            last_table[item]=last_table[item]+1
        elif not last_table.has_key(item) and item!='-':
            last_table[item]=1
            
k=2
while True:
    values=last_table.values()
    keys=last_table.keys()
    print keys  
    if len(keys)<=1:
        break

    print last_table
    print ''
    prune(last_table,3)
    print last_table
    print ''
    self_join(db,last_table,k)
    k=k+1
    
    

