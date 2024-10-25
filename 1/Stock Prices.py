""" cases = int(input())

for i in range(cases):
    orders = int(input())
    ask = '-'
    cantAsk = {}
    bid = '-'
    cantBid = {}
    stock = '-'

    for j in range(orders):
        order = input().split()

        if order[0] == "sell":
            if ask == '-':
                ask = order[4]

            if cantAsk and int(order[4]) < min(cantAsk):
                ask = order[4]

            cantAsk[int(order[4])] = cantAsk.get(int(order[4]), 0) + int(order[1])

        else:
            if bid == '-':
                bid = order[4]

            cantBid[int(order[4])] = cantBid.get(int(order[4]), 0) + int(order[1])
            
            if cantAsk:
                bid = str(max(cantBid))

        if ask != '-' and bid != '-' and int(ask) <= int(bid): # Hay trato
            stock = ask
            newAsk = cantAsk[int(ask)]

            if newAsk - cantBid[int(bid)] == 0:
                del cantAsk[int(ask)]
                del cantBid[int(bid)]

            elif newAsk - cantBid[int(bid)] < 0:
                del cantAsk[int(ask)]
                cantBid[int(bid)] = cantBid[int(bid)] - newAsk
    
            elif newAsk - cantBid[int(bid)] > 0:
                cantAsk[int(ask)] = newAsk - cantBid[int(bid)]
                del cantBid[int(bid)]

            if cantAsk:
                ask = str(min(cantAsk))
            else:
                ask = '-'
            
            if cantBid:
                bid = str(max(cantBid))
            else:
                bid = '-'
            print(ask, bid, stock)

        else:
            print(ask, bid, stock) """

""" cases = int(input())

for i in range(cases):
    orders = int(input())
    ask = '-'
    cantAsk = {}
    bid = '-'
    cantBid = {}
    stock = '-'

    for j in range(orders):
        order = input().split()

        price = int(order[4])
        quantity = int(order[1])

        if order[0] == "sell":
            # Actualiza el precio de venta (ask)
            if ask == '-' or price < int(ask):
                ask = str(price)

            cantAsk[price] = cantAsk.get(price, 0) + quantity

        else:  # "buy"
            # Actualiza el precio de compra (bid)
            if bid == '-' or price > int(bid):
                bid = str(price)

            cantBid[price] = cantBid.get(price, 0) + quantity

        # Si se puede hacer un trato
        if ask != '-' and bid != '-' and int(ask) <= int(bid):
            stock = ask
            ask_price = int(ask)
            bid_price = int(bid)
            available_shares = min(cantAsk[ask_price], cantBid[bid_price])

            cantAsk[ask_price] -= available_shares
            cantBid[bid_price] -= available_shares

            if cantAsk[ask_price] == 0:
                del cantAsk[ask_price]
                ask = str(min(cantAsk)) if cantAsk else '-'

            if cantBid[bid_price] == 0:
                del cantBid[bid_price]
                bid = str(max(cantBid)) if cantBid else '-'

            print(ask, bid, stock)

        else:
            print(ask, bid, stock) """

from collections import Counter

cases = int(input())

for i in range(cases):
    orders = int(input())
    ask = '-'
    cantAsk = Counter()
    bid = '-'
    cantBid = Counter()
    stock = '-'

    for j in range(orders):
        order = input().split()
        action, amount, _, price = order[0], int(order[1]), order[2], int(order[4])

        if action == "sell":
            cantAsk[price] += amount
            if ask == '-' or price < int(ask):
                ask = str(price)
        
        else:  # action == "buy"
            cantBid[price] += amount
            if bid == '-' or price > int(bid):
                bid = str(price)

        while ask != '-' and bid != '-' and int(ask) <= int(bid):
            stock = ask
            deal_amount = min(cantAsk[int(ask)], cantBid[int(bid)])

            cantAsk[int(ask)] -= deal_amount
            cantBid[int(bid)] -= deal_amount

            if cantAsk[int(ask)] == 0:
                del cantAsk[int(ask)]
                ask = str(min(cantAsk)) if cantAsk else '-'

            if cantBid[int(bid)] == 0:
                del cantBid[int(bid)]
                bid = str(max(cantBid)) if cantBid else '-'

        print(ask, bid, stock)
