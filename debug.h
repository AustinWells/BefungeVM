char* op_names[] =
{
    ['+']  = "ADD",
    ['-']  = "SUB",
    ['*']  = "MULT",
    ['/']  = "DIV",
    ['%']  = "MOD",
    ['!']  = "NOT",
    ['`']  = "GT ",
    ['>']  = "PCR",
    ['<']  = "PCL",
    ['^']  = "PCU",
    ['v']  = "PCD",
    ['?']  = "PCRAND",
    ['_']  = "HIF",
    ['|']  = "VIF",
    ['"']  = "STRING",
    [':']  = "DUP",
    ['\\'] = "SWAP",
    ['$']  = "POPR",
    ['.']  = "POPI",
    [',']  = "POPC",
    ['#']  = "BRIDGE",
    ['g']  = "GET",
    ['p']  = "PUT",
    ['&']  = 'READI,'
    ['~']  = "READC",
    ['@']  = "END",
    [NOOP] = "NOOP",
    [';']  = "IGNORE",

    [-99] = "LEFT",
    [-98] = "RIGHT",
    [-97] = "UP",
    [-96] = "DOWN"
};
