class PlayerInventaryBuilder
{
	void CreateInventory(PlayerBase player)
	{	
		array<string> items1 = {"FlatCap_Brown", "Jeans_Blue", "AthleticShoes_Grey", "WoolCoat_GreyCheck"};
		array<string> items2 = {"SlacksPants_DarkGrey", "AthleticShoes_Brown", "WoolCoat_Blue", "FlatCap_GreyCheck"};
		array<string> items3 = {"FlatCap_Black", "TrackSuitPants_Blue", "DressShoes_Black", "ManSuit_Black"};
		array<string> items4 = {"SlacksPants_Black", "DressShoes_Black", "ManSuit_Blue"};
		array<string> items5 = {"SlacksPants_Brown", "Shirt_WhiteCheck", "DressShoes_Brown"};
		
		array<array<string>> items = {
				items1,
				items2,
				items3,
				items4,
				items5
			};
		
		RemoveAllItems(player);      
		int key = Math.RandomIntInclusive(0,4);   	

		foreach(string item : items[key]) {
			player.GetInventory().CreateInInventory(item);
		}   			
		player.GetInventory().CreateInInventory("Apple");
		player.GetInventory().CreateInInventory("Rag");	
	}
		
	private array<EntityAI> GetItemListInObject(PlayerBase player, EntityAI item, bool checkPlayer)
	{
		array<EntityAI> itemList = new array<EntityAI>; 
		itemList.Clear();
		int	attIdx = 0; 
		int attCount = 0; 
		EntityAI Item;
		if ((player) && (checkPlayer))
		{
			attCount = player.GetInventory().AttachmentCount(); 
			for (attIdx	= 0; attIdx < attCount; attIdx++)
			{
				Item = player.GetInventory().GetAttachmentFromIndex(attIdx);
				if ( Item.IsItemBase() )
				{
					itemList.Insert(Item);
				}
			}
		}
		if ((item) && !checkPlayer)
		{
			attCount = item.GetInventory().AttachmentCount();
			for (attIdx	= 0; attIdx < attCount; attIdx++)
			{
				Item = item.GetInventory().GetAttachmentFromIndex(attIdx);
				if ( Item.IsItemBase() )
				{
					itemList.Insert(Item);
				}
			}
		}
		return itemList;		
	}
	
	void RemoveAllItems(PlayerBase player) 
	{
		private array<EntityAI> itemListPlayer = new array<EntityAI>;
		private array<EntityAI> ItemsForDelete = new array<EntityAI>;
		private EntityAI itemInHandsPlayer = player.GetHumanInventory().GetEntityInHands();
		if (itemInHandsPlayer != NULL)
		{
			if (player.CanDropEntity(itemInHandsPlayer) && player.GetHumanInventory().CanRemoveEntityInHands())
			{
				ItemsForDelete.Insert(itemInHandsPlayer);
			}
		}
		itemListPlayer = GetItemListInObject(player, NULL, true);		
		if (itemListPlayer.Count() > 0)
		{			
			foreach(EntityAI ItemPlayer: itemListPlayer)
			{
				private array<EntityAI> ItemInItemInInventory = GetItemListInObject(NULL, ItemPlayer, false);
				private CargoBase cargo = ItemPlayer.GetInventory().GetCargo();		
				if(cargo) 
				{
					if (cargo.GetItemCount() > 0)
					{
						for (int f = 0; f < cargo.GetItemCount(); f++)
						{
							if(cargo.GetItem(f))
							{						
								ItemsForDelete.Insert(cargo.GetItem(f));
							}
						}														
					}
				}									
				if (ItemInItemInInventory.Count() > 0)
				{
					foreach(EntityAI items: ItemInItemInInventory)
					{
						if(items)
						{						
							ItemsForDelete.Insert(items);
						}
					}		
				}
				if(ItemPlayer)
				{	
					ItemsForDelete.Insert(ItemPlayer);
				}
			}										
		} 
		if (ItemsForDelete.Count() > 0)
		{
			foreach(EntityAI item: ItemsForDelete)
			{
				if(item)
				{														
					GetGame().ObjectDelete(item);													
				}												
			}
		}
	}
}