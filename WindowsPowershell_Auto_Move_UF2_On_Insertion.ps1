# Tyler Meier - 9/6/2024 - ECD501
# First ensure the Pico is unplugged, then run this script.
# Next, plug in Pico while holding BOOTSEL as normal, and this script will automatically load the
# uf2 file at $sourceFile into the Pico. To load an updated uf2 of the same name, just unplug and replug the Pico in the same way.
# To change the uf2 filename, also change the $destinationFile value.

# Define the source file and the target folder name
$sourceFile = "Z:\Bare-Metal-Raspberry-PI-Pico\test_led.uf2" # Change this to the file you want to move

# Function to check drives and move file
function Move-FileToUSB {
    # Get the list of currently connected drives
    $initialDrives = Get-PSDrive -PSProvider FileSystem | Select-Object -ExpandProperty Root

    # Loop to continuously monitor for new drives
    while ($true) {
        # Get the updated list of drives
        $currentDrives = Get-PSDrive -PSProvider FileSystem | Select-Object -ExpandProperty Root

        # Find the new drive by comparing initial and current drive lists
        $newDrives = Compare-Object -ReferenceObject $initialDrives -DifferenceObject $currentDrives |
            Where-Object { $_.SideIndicator -eq '=>' } | Select-Object -ExpandProperty InputObject

        # If a new drive is detected, it could be the USB
        if ($newDrives) {
            # Assume the first detected new drive is the USB
            $usbDrive = $newDrives[0]
            Write-Host "New USB detected: $usbDrive"

            # Define the destination path on the USB
            $destinationFile = "D:\test_led.uf2"

            try {
                # Attempt to move the file
                Copy-Item -Path $sourceFile -Destination $destinationFile -Force
                Write-Host "File moved to USB: $destinationFile"
            } catch {
                Write-Host "Error moving file: $_"
            }


        }

        # Wait for a few seconds before checking again
        Start-Sleep -Seconds 2
    }
}

Move-FileToUSB


