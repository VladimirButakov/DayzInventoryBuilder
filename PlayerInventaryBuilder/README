#DayzInventoryBuilder

1.В файле: {папка с вашим сервером}\mpmissions\dayzOffline.chernarusplus\init.c в самом верху файла добавить: #include "$CurrentDir:mpmissions\dayzOffline.chernarusplus\PlayerInventaryBuilder\PlayerInventaryBuilder.c" ref PlayerInventaryBuilder InventoryBuilder = new PlayerInventaryBuilder();

2.В функции: StartingEquipSetup перед ее закрывающей скобкой '}' добавить: InventoryBuilder.CreateInventory(player);
