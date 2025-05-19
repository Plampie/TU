class Worker:
    def __init__(self, worker_num, fname, lname, work_experience_company, salary, age):
        self.worker_num = worker_num
        self.fname = fname
        self.lname = lname
        self.work_experience_company = work_experience_company
        self.salary = salary
        self.age = age

    def worker_information(self):
        return f"Worker Number: {self.worker_num}, Name: {self.fname} {self.lname}, " \
               f"Experience: {self.work_experience_company} years, Salary: {self.salary}, Age: {self.age}"

    def salary_bonus(self):
        if self.work_experience_company < 5:
            bonus = self.salary * 0.005
        elif 5 <= self.work_experience_company <= 10:
            bonus = self.salary * 0.015
        else:
            bonus = self.salary * 0.02
        return self.salary + bonus


def search_by_num(workers_list, worker_num):
    for worker in workers_list:
        if worker.worker_num == worker_num:
            return True
    return False


def search_by_name_experience(workers_list, fname, work_experience_company):
    result = []
    for worker in workers_list:
        if worker.fname == fname and worker.work_experience_company == work_experience_company:
            result.append(worker)
    return result


def add_worker(workers_list, worker):
    workers_list.append(worker)


def remove_worker(workers_list, worker_num):
    for worker in workers_list:
        if worker.worker_num == worker_num:
            workers_list.remove(worker)
            print("Information deleted!")
            return
    print("Wrong worker number!")


# Example program for managing workers:
workers_list = []

# Entering workers
num_workers = int(input("Enter the number of workers: "))
for _ in range(num_workers):
    worker_num = int(input("Enter worker number: "))
    fname = input("Enter first name: ")
    lname = input("Enter last name: ")
    work_experience_company = int(input("Enter work experience (years): "))
    salary = float(input("Enter salary: "))
    age = int(input("Enter age: "))
    new_worker = Worker(worker_num, fname, lname, work_experience_company, salary, age)
    add_worker(workers_list, new_worker)

# Searching for a worker by number
search_num = int(input("Enter worker number to search: "))
if search_by_num(workers_list, search_num):
    print("Worker found!")
else:
    print("Worker not found!")

# Searching for workers by name and experience
search_fname = input("Enter name to search: ")
search_experience = int(input("Enter work experience to search: "))
matching_workers = search_by_name_experience(workers_list, search_fname, search_experience)
if matching_workers:
    print("Matching workers:")
    for worker in matching_workers:
        print(worker.worker_information())
else:
    print("No matching workers found.")

# Removing a worker
remove_num = int(input("Enter worker number to remove: "))
remove_worker(workers_list, remove_num)

# Displaying information for all workers
print("All workers:")
for worker in workers_list:
    print(worker.worker_information())