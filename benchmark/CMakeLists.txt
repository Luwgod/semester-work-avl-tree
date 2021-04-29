# Здесь вы можете создавать свои исполняемые файлы (executables)
# исполянемый файл = контрольный тест

# Пример создания контрольного теста (исполняемого файла) под названием demo_benchmark.
# Исходный код предоставлен в файле demo_benchmark.cpp текущей директории.
add_executable(insert_benchmark insert_benchmark.cpp)
add_executable(delete_benchmark delete_benchmark.cpp)
add_executable(search_benchmark search_benchmark.cpp)

# Примечание: Не забываем подключить (прилинковать) библиотеку ${PROJECT_NAME} с реализацией структуры данных.
target_link_libraries(insert_benchmark PRIVATE project_paths project_warnings ${PROJECT_NAME})
target_link_libraries(delete_benchmark PRIVATE project_paths project_warnings ${PROJECT_NAME})
target_link_libraries(search_benchmark PRIVATE project_paths project_warnings ${PROJECT_NAME})


