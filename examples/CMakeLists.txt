# Добавьте сюда исполняемые файлы с примерами работы со структурой данных

add_executable(insert_example  insert_example.cpp)
add_executable(delete_example  delete_example.cpp)
add_executable(search_example  search_example.cpp)

# Примечание: Не забываем подключить (прилинковать) библиотеку ${PROJECT_NAME} с реализацией структуры данных.
target_link_libraries(insert_example PRIVATE project_paths project_warnings ${PROJECT_NAME})
target_link_libraries(delete_example PRIVATE project_paths project_warnings ${PROJECT_NAME})
target_link_libraries(search_example PRIVATE project_paths project_warnings ${PROJECT_NAME})
