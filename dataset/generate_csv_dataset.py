import csv, random

key = False

data_file_sizes = [100, 500, 1000, 5000,
                   10000, 50000, 100000,  500000,
                   1000000, 5000000]
data_set_numbers = ['01', '02', '03', '04', '05', '06',
                    '07', '08', '09', '10']
if key:
    for set_num in data_set_numbers:
        for size in data_file_sizes:
            with open(f'data/{set_num}/{size}.csv', mode='w', newline='') as data_file:
                int_writer = csv.writer(data_file, delimiter=',')

                nums_list = list(range(size+1))
                random.shuffle(nums_list)
                for num in nums_list:
                    int_writer.writerow([num])
