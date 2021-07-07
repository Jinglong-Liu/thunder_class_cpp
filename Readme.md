添加了教师

更新客户端文件结构

已完成到聊天室(仅学生)

踩过的坑：

tcpSocket->readAll()可能会读到多个Message
所以拆分根据报文头信息拆分Message是一种容易想到的方法