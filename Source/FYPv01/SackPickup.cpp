// Fill out your copyright notice in the Description page of Project Settings.


#include "SackPickup.h"



// Fill out your copyright notice in the Description page of Project Settings.

void USackPickup::Random_Drop_Rate(TArray <FLoot_Box> Loot_Classes, TSubclassOf <AActor>& Drop_Item, bool& Drop_Rate_Equal_100, int& ItemID)
{
    // Declare temporary integer array for storing all "Drop Rates"

    TArray <int32> DropRateArray;
    int32 EqualTo100 = 0;

    // Add input array drop rates to temporary array while summing the values to create a range "max" for each Loot Item

    for (int x = 0; x < Loot_Classes.Num(); ++x)
    {
        if (x == 0)
        {
            DropRateArray.Add(FMath::Abs(Loot_Classes[x].Drop_Rate));
        }
        else
        {
            DropRateArray.Add(FMath::Abs(Loot_Classes[x].Drop_Rate) + (DropRateArray[x - 1]));
        }
    }

    // Ensure all "Drop Rates" sum to EXACTLY 100

    if (DropRateArray.Last() == 100)
    {
        // Generate a random number

        int32 DropIndex = UKismetMathLibrary::RandomIntegerInRange(1, 100);

        // Start with the lowest range "max value" and keep moving up until random int <= max of range

        for (int x = 0; x < DropRateArray.Num(); ++x)
        {
            if (DropIndex <= DropRateArray[x])
            {
                Drop_Item = Loot_Classes[x].Item_Class;
                ItemID = x;
                break;
            }
            else
                ;
        }
        Drop_Rate_Equal_100 = true;
    }

    // If drop rates do NOT sum to exactly 100 return a false boolean and a null drop item

    else
    {
        Drop_Item = nullptr;
        Drop_Rate_Equal_100 = false;
    }
}