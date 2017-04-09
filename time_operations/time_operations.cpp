
std::string getCurrentDateTime() 
{
    struct tm* timeInfo;
    char ptrDateTime[30];
    ptrDateTime[0] = '\0';
    time_t now = time(NULL);

    timeInfo = localtime(&now);

    if (now != -1 && timeInfo != NULL) 
    {
        strftime(ptrDateTime, 30, "%Y-%m-%d %H:%M:%S", timeInfo);
    }
    return std::string(ptrDateTime);
}
