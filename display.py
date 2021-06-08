import matplotlib.pyplot as plt
import sys


# get values from command line argument
checking = float(sys.argv[1])
savings = float(sys.argv[2])

# create bar graph comparing checking and savings accounts
bar_graph = plt.subplot(111)
bar_graph.bar(1, checking , width=0.5, color='g', align='edge')
bar_graph.bar(2, savings, width=0.5, color='b', align='center')

# fix titles and axes
plt.gcf().canvas.set_window_title('Bank Account Information Visualized')
plt.title('Checking and Savings Balances')
plt.xlabel('Green is Checking, Blue is Savings')
plt.ylabel('Money in Account')

# Display the graph in a new window
plt.show()

# clear the figure to allow for the pie chart
plt.clf()


#create labels and values for pie chart
labels = 'Checking', 'Savings'
values = [checking, savings]

# will separate the slices
explode = (0, 0.1)

# create the pie chart
figure, axes = plt.subplots()
axes.pie(values, explode=explode, labels=labels, autopct='%1.1f%%',
        shadow=True, startangle=180)
axes.axis('equal')

# add title and window title
plt.title('Checking and Savings Pie Chart')
plt.gcf().canvas.set_window_title('Banking Pie Chart')

# show the pie chart
plt.show()

plt.clf()